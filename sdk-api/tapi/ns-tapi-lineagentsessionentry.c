typedef struct lineagentsession_tag {
  HAGENTSESSION hAgentSession;
  HAGENT        hAgent;
  GUID          GroupID;
  DWORD         dwWorkingAddressID;
} LINEAGENTSESSIONENTRY, *LPLINEAGENTSESSIONENTRY;