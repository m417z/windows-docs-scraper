typedef struct _MSV1_0_INTERACTIVE_PROFILE {
  MSV1_0_PROFILE_BUFFER_TYPE MessageType;
  USHORT                     LogonCount;
  USHORT                     BadPasswordCount;
  LARGE_INTEGER              LogonTime;
  LARGE_INTEGER              LogoffTime;
  LARGE_INTEGER              KickOffTime;
  LARGE_INTEGER              PasswordLastSet;
  LARGE_INTEGER              PasswordCanChange;
  LARGE_INTEGER              PasswordMustChange;
  UNICODE_STRING             LogonScript;
  UNICODE_STRING             HomeDirectory;
  UNICODE_STRING             FullName;
  UNICODE_STRING             ProfilePath;
  UNICODE_STRING             HomeDirectoryDrive;
  UNICODE_STRING             LogonServer;
  ULONG                      UserFlags;
} MSV1_0_INTERACTIVE_PROFILE, *PMSV1_0_INTERACTIVE_PROFILE;