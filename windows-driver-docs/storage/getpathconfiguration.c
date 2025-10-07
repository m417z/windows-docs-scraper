void GetPathConfiguration(
   [in, Description("64-bit Path Identifier"):amended] uint64 PathID,
   [out] uint32                                               EntryCount,
   [out, WmiSizeIs("EntryCount")] SCSI_ADDR                   Address[]
);