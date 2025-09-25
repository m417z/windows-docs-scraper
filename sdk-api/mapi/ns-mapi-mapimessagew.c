typedef struct {
  ULONG            ulReserved;
  PWSTR            lpszSubject;
  PWSTR            lpszNoteText;
  PWSTR            lpszMessageType;
  PWSTR            lpszDateReceived;
  PWSTR            lpszConversationID;
  FLAGS            flFlags;
  lpMapiRecipDescW lpOriginator;
  ULONG            nRecipCount;
  lpMapiRecipDescW lpRecips;
  ULONG            nFileCount;
  lpMapiFileDescW  lpFiles;
} MapiMessageW, *lpMapiMessageW;