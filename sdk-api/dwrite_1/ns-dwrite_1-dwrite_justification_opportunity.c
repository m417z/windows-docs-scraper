struct DWRITE_JUSTIFICATION_OPPORTUNITY {
  FLOAT  expansionMinimum;
  FLOAT  expansionMaximum;
  FLOAT  compressionMaximum;
  UINT32 expansionPriority : 8;
  UINT32 compressionPriority : 8;
  UINT32 allowResidualExpansion : 1;
  UINT32 allowResidualCompression : 1;
  UINT32 applyToLeadingEdge : 1;
  UINT32 applyToTrailingEdge : 1;
  UINT32 reserved : 12;
};