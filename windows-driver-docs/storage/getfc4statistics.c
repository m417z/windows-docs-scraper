void GetFC4Statistics(
   [out, HBA_STATUS_QUALIFIERS] HBA_STATUS HBAStatus,
   [in, HBAType("HBA_WWN")] uint8          PortWWN,
   [in] uint8                              FC4Type,
   [out] MSFC_FC4STATISTICS                FC4Statistics
);