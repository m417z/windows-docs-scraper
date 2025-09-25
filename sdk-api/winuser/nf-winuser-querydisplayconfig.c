LONG QueryDisplayConfig(
  [in]            UINT32                    flags,
  [in, out]       UINT32                    *numPathArrayElements,
  [out]           DISPLAYCONFIG_PATH_INFO   *pathArray,
  [in, out]       UINT32                    *numModeInfoArrayElements,
  [out]           DISPLAYCONFIG_MODE_INFO   *modeInfoArray,
  [out, optional] DISPLAYCONFIG_TOPOLOGY_ID *currentTopologyId
);