typedef struct {
  ULONG           ulReserved;
  LPSTR           lpszSubject;
  LPSTR           lpszNoteText;
  LPSTR           lpszMessageType;
  LPSTR           lpszDateReceived;
  LPSTR           lpszConversationID;
  FLAGS           flFlags;
  lpMapiRecipDesc lpOriginator;
  ULONG           nRecipCount;
  lpMapiRecipDesc lpRecips;
  ULONG           nFileCount;
  lpMapiFileDesc  lpFiles;
} MapiMessage, *lpMapiMessage;