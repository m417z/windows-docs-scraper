struct DWRITE_SCRIPT_PROPERTIES {
  UINT32 isoScriptCode;
  UINT32 isoScriptNumber;
  UINT32 clusterLookahead;
  UINT32 justificationCharacter;
  UINT32 restrictCaretToClusters : 1;
  UINT32 usesWordDividers : 1;
  UINT32 isDiscreteWriting : 1;
  UINT32 isBlockWriting : 1;
  UINT32 isDistributedWithinCluster : 1;
  UINT32 isConnectedWriting : 1;
  UINT32 isCursiveWriting : 1;
  UINT32 reserved : 25;
};