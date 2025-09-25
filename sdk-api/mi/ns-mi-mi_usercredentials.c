typedef struct _MI_UserCredentials {
  const MI_Char *authenticationType;
  union {
    MI_UsernamePasswordCreds usernamePassword;
    const MI_Char            *certificateThumbprint;
  } credentials;
} MI_UserCredentials;