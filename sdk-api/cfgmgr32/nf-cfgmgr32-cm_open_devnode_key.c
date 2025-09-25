CMAPI CONFIGRET CM_Open_DevNode_Key(
  [in]  DEVINST        dnDevNode,
  [in]  REGSAM         samDesired,
  [in]  ULONG          ulHardwareProfile,
  [in]  REGDISPOSITION Disposition,
  [out] PHKEY          phkDevice,
  [in]  ULONG          ulFlags
);