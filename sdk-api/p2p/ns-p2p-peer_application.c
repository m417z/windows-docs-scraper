typedef struct peer_application_tag {
  GUID      id;
  PEER_DATA data;
  PWSTR     pwzDescription;
} PEER_APPLICATION, *PPEER_APPLICATION;