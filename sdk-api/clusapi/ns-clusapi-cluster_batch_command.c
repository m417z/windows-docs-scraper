typedef struct _CLUSTER_BATCH_COMMAND {
  CLUSTER_REG_COMMAND Command;
  DWORD               dwOptions;
  LPCWSTR             wzName;
  BYTE const          *lpData;
  DWORD               cbData;
} CLUSTER_BATCH_COMMAND;