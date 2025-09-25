typedef struct _CLUSTER_READ_BATCH_COMMAND {
  CLUSTER_REG_COMMAND Command;
  DWORD               dwOptions;
  LPCWSTR             wzSubkeyName;
  LPCWSTR             wzValueName;
  BYTE const          *lpData;
  DWORD               cbData;
} CLUSTER_READ_BATCH_COMMAND;