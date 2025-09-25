## Description

The **HMAT_ENTRY** structure contains the Heterogeneous Memory Attribute Table (HMAT) information for the table. The structure can contain one of three HMAT types: Memory Subsystem Address Range (MSAR), System Locality Latency and Bandwidth Information (SLLBI), or Memory Side Cache Information (MSCI).

## Members

### `Type`

A **USHORT** value containing the HMAT table type.

### `Reserved`

Reserved for future use.

### `Length`

A **ULONG** value containing the size of the table.

### `DUMMYUNIONNAME`

Defines the **DUMMYUNIONNAME** union.

### `DUMMYUNIONNAME.Msar`

Defines the **Msar** structure.

### `DUMMYUNIONNAME.Msar.Flags`

Defines the **Flags** union.

### `DUMMYUNIONNAME.Msar.Flags.DUMMYSTRUCTNAME`

Defines the **DUMMYSTRUCTNAME** structure.

### `DUMMYUNIONNAME.Msar.Flags.DUMMYSTRUCTNAME.ProcessorProximityDomainValid`

Defines the **USHORT** member **ProcessorProximityDomainValid**.

### `DUMMYUNIONNAME.Msar.Flags.DUMMYSTRUCTNAME.Reserved0`

Reserved for future use.

### `DUMMYUNIONNAME.Msar.Flags.DUMMYSTRUCTNAME.Reserved1`

Reserved for future use.

### `DUMMYUNIONNAME.Msar.Flags.DUMMYSTRUCTNAME.Reserved`

Reserved for future use.

### `DUMMYUNIONNAME.Msar.Flags.AsUSHort`

Defines the **USHORT** member **AsUSHort**.

### `DUMMYUNIONNAME.Msar.Reserved1`

Reserved for future use.

### `DUMMYUNIONNAME.Msar.ProcessorProximityDomain`

Defines the **ULONG** member **ProcessorProximityDomain**.

### `DUMMYUNIONNAME.Msar.MemoryProximityDomain`

Defines the **ULONG** member **MemoryProximityDomain**.

### `DUMMYUNIONNAME.Msar.Reserved2`

Reserved for future use.

### `DUMMYUNIONNAME.Msar.Reserved3`

Reserved for future use.

### `DUMMYUNIONNAME.Msar.Reserved4`

Reserved for future use.

### `DUMMYUNIONNAME.Sllbi`

Defines the **Sllbi** union.

### `DUMMYUNIONNAME.Sllbi.Flags`

Defines the **Flags** union.

### `DUMMYUNIONNAME.Sllbi.Flags.DUMMYSTRUCTNAME`

Defines the **DUMMYSTRUCTNAME** structure.

### `DUMMYUNIONNAME.Sllbi.Flags.DUMMYSTRUCTNAME.MemoryHierarchy`

Defines the **UCHAR** member **MemoryHierarchy**.

### `DUMMYUNIONNAME.Sllbi.Flags.DUMMYSTRUCTNAME.MinTransferSizeToAchieveValues`

Defines the **UCHAR** member **MinTransferSizeToAchieveValues**.

### `DUMMYUNIONNAME.Sllbi.Flags.DUMMYSTRUCTNAME.NonSequentialTransfers`

Defines the **UCHAR** member **NonSequentialTransfers**.

### `DUMMYUNIONNAME.Sllbi.Flags.DUMMYSTRUCTNAME.Reserved`

Reserved for future use.

### `DUMMYUNIONNAME.Sllbi.Flags.AsUChar`

Defines the **UCHAR** member **AsUChar**.

### `DUMMYUNIONNAME.Sllbi.DataType`

Defines the **UCHAR** member **DataType**.

### `DUMMYUNIONNAME.Sllbi.MinTransferSize`

Defines the **UCHAR** member **MinTransferSize**.

### `DUMMYUNIONNAME.Sllbi.Reserved1`

Reserved for future use.

### `DUMMYUNIONNAME.Sllbi.NumberOfInitiatorProximityDomains`

Defines the **ULONG** member **NumberOfInitiatorProximityDomains**.

### `DUMMYUNIONNAME.Sllbi.NumberOfTargetProximityDomains`

Defines the **ULONG** member **NumberOfTargetProximityDomains**.

### `DUMMYUNIONNAME.Sllbi.Reserved2`

Reserved for future use.

### `DUMMYUNIONNAME.Sllbi.EntryBaseUnit`

Defines the **ULONGLONG** member **EntryBaseUnit**.

### `DUMMYUNIONNAME.Msci`

Defines the **Msci** union.

### `DUMMYUNIONNAME.Msci.MemoryProximityDomain`

Defines the **ULONG** member **MemoryProximityDomain**.

### `DUMMYUNIONNAME.Msci.Reserved1`

Reserved for future use.

### `DUMMYUNIONNAME.Msci.MemorySideCacheSize`

Defines the **ULONGLONG** member **MemorySideCacheSize**.

### `DUMMYUNIONNAME.Msci.CacheAttributes`

Defines the **CacheAttributes** union.

### `DUMMYUNIONNAME.Msci.CacheAttributes.DUMMYSTRUCTNAME`

Defines the **DUMMYSTRUCTNAME** structure.

### `DUMMYUNIONNAME.Msci.CacheAttributes.DUMMYSTRUCTNAME.TotalCacheLevels`

Defines the **ULONG** member **TotalCacheLevels**.

### `DUMMYUNIONNAME.Msci.CacheAttributes.DUMMYSTRUCTNAME.CacheLevel`

Defines the **ULONG** member **CacheLevel**.

### `DUMMYUNIONNAME.Msci.CacheAttributes.DUMMYSTRUCTNAME.CacheAssociativity`

Defines the ULONG member CacheAssociativity.

### `DUMMYUNIONNAME.Msci.CacheAttributes.DUMMYSTRUCTNAME.WritePolicy`

Defines the **ULONG** member **WritePolicy**.

### `DUMMYUNIONNAME.Msci.CacheAttributes.DUMMYSTRUCTNAME.CacheLineSize`

Defines the **ULONG** member **CacheLineSize**.

### `DUMMYUNIONNAME.Msci.CacheAttributes.AsULong`

Defines the **ULONG** member **AsULong**.

### `DUMMYUNIONNAME.Msci.Reserved2`

Reserved for future use.

### `DUMMYUNIONNAME.Msci.NumberOfSmBiosHandles`

Defines the **USHORT** member **NumberOfSmBiosHandles**.

## Remarks

## See also