typedef struct _KERB_CHANGEPASSWORD_REQUEST {
  KERB_PROTOCOL_MESSAGE_TYPE MessageType;
  UNICODE_STRING             DomainName;
  UNICODE_STRING             AccountName;
  UNICODE_STRING             OldPassword;
  UNICODE_STRING             NewPassword;
  BOOLEAN                    Impersonating;
} KERB_CHANGEPASSWORD_REQUEST, *PKERB_CHANGEPASSWORD_REQUEST;