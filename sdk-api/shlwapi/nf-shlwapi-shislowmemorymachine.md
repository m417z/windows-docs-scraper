# SHIsLowMemoryMachine function

## Description

Not supported.

## Parameters

### `dwType` [in]

Type: **DWORD**

The type of machine being examined. The following is the only recognized value.

#### ILMM_IE4

An older (circa 1997), low-end machine. Since system resources in general were lower on these older machines, the low-memory threshold is accordingly lower.

## Return value

Type: **BOOL**

**TRUE** if the machine is considered low on resources, **FALSE** otherwise.

**Note** Always returns **FALSE** under Windows XP.