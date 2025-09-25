typedef struct _BDANODE_DESCRIPTOR {
  ULONG ulBdaNodeType;
  GUID  guidFunction;
  GUID  guidName;
} BDANODE_DESCRIPTOR, *PBDANODE_DESCRIPTOR;