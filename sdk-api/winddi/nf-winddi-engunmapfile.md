# EngUnmapFile function

## Description

The **EngUnmapFile** function unmaps the view of a file from [system space](https://learn.microsoft.com/windows-hardware/drivers/).

## Parameters

### `iFile` [in]

Pointer to the identifier of the mapped file. This identifier was obtained in a prior call to [EngMapFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapfile).

## Return value

**EngUnmapFile** returns **TRUE** upon success. Otherwise, it returns **FALSE**.

## See also

[EngMapFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmapfile)