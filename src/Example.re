// module FailingQuery = [%graphql
//   {|
//   query issueMilestone($owner: String!, $repo: String!, $number: Int!) {
//     repository(owner:$owner, name:$repo) {
//       issue(number:$number) {
//         id
//         milestone { id }
//         timelineItems(itemTypes:[CLOSED_EVENT],last:1) {
//           totalCount
//           nodes {
//             __typename
//             ... on ClosedEvent {
//               closer {
//                 __typename
//                 ... on PullRequest {
//                   id
//                   milestone { id }
//                 }
//                 ... on Commit {
//                   associatedPullRequests(first: 2) {
//                     nodes {
//                       id
//                       milestone { id }
//                     }
//                   }
//                 }
//               }
//             }
//           }
//         }
//       }
//     }
//   }
// |}
// ];

module WorkingQuery = [%graphql
  {|
  query issueMilestone($owner: String!, $repo: String!, $number: Int!) {
    repository(owner:$owner, name:$repo) {
      issue(number:$number) {
        id
        milestone { id }
        timelineItems(itemTypes:[CLOSED_EVENT],last:1) {
          totalCount
          nodes {
            ... on ClosedEvent {
              closer {
                ... on PullRequest {
                  id
                  milestone { id }
                }
                ... on Commit {
                  associatedPullRequests(first: 2) {
                    nodes {
                      id
                      milestone { id }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
|}
];
