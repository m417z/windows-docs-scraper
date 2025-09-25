typedef struct peer_contact_tag {
  PWSTR                 pwzPeerName;
  PWSTR                 pwzNickName;
  PWSTR                 pwzDisplayName;
  PWSTR                 pwzEmailAddress;
  BOOL                  fWatch;
  PEER_WATCH_PERMISSION WatcherPermissions;
  PEER_DATA             credentials;
} PEER_CONTACT, *PPEER_CONTACT;