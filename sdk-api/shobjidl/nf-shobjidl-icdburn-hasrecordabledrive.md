# ICDBurn::HasRecordableDrive

## Description

Scans the system for a CD drive with write-capability, returning **TRUE** if one is found.

## Parameters

### `pfHasRecorder` [out]

Type: **BOOL***

A pointer to a Boolean value containing **TRUE** if a suitable device is located, **FALSE** otherwise.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This search does not rely on the state of the **Enable cd writing on this drive** option found on the drive's property sheet. Instead, the determination is based on IMAPI.