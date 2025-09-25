typedef struct _MI_ServerFT {
  MI_Result()(MI_Uint32 *version) * GetVersion;
  MI_Result((const MI_Char **systemName) * )GetSystemName;
} MI_ServerFT;