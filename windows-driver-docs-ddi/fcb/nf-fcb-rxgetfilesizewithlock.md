# RxGetFileSizeWithLock function

## Description

**RxGetFileSizeWithLock** gets the file size in the FCB structure using a lock to ensure that the 64-bit value is read consistently.

## Parameters

### `Fcb` [in]

A pointer to the FCB structure.

### `FileSize` [out]

A pointer where the file size file will be stored on output.

## Remarks

The **RxGetFileSizeWithLock** routine is not normally called by network mini-redirector drivers directly. RDBSS calls this routine internally when an I/O request packet is received for IRP_MJ_QUERY_INFORMATION, IRP_MJ_SET_INFORMATION, IRP_MJ_READ, or IRP_MJ_WRITE. These IRPs are normally received by RDBSS in response to a user-mode application requesting operations on a file. It is also possible for another kernel driver to issue such an IRP.

These IRPs will normally result in a call to one of the **MRxQueryFileInfo, MRxQuerySdInfo**, **MRxLowIORead**, or **MRxLowIOWrite** routines provided by the network mini-redirector.

**RxGetFileSizeWithLock** acquires a lock on the FCB structure and then reads the file size, and then frees the lock. This lock assures that the file size is protected during this operation, since file size is a 64-bit quantity that requires at least two instructions to read on 32-bit processors.

## See also

[MRxQueryFileInfo](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxqueryfileinfo)

[MRxQuerySdInfo](https://learn.microsoft.com/windows-hardware/drivers/ifs/mrxquerysdinfo)

[The FCB Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-fcb-structure)