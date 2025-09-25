# IStreamUnbufferedInfo::GetSectorSize

## Description

Retrieves the number of bytes per sector on the disk currently being used. When using unbuffered input/output (I/O), it is important to know the size of the sectors on the disk being read in order to ensure proper byte alignment.

## Parameters

### `pcbSectorSize` [out]

Type: **ULONG***

When this method returns successfully, contains a pointer to a **ULONG** value that represents the number of bytes per sector for the disk.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.