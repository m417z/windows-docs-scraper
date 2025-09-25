# ICrmLogControl::WriteLogRecord

## Description

The CRM Worker and CRM Compensator use this method to write unstructured log records to the log. This method would typically be used by CRM components written in C++. Records are written lazily to the log and must be forced before they become durable. (See [ICrmLogControl::ForceLog](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icrmlogcontrol-forcelog).)

## Parameters

### `rgBlob` [in]

An array of BLOBs that form the log record. A BLOB is a Windows data type that is used to store an arbitrary amount of binary data.

### `cBlob` [in]

The number of BLOBs in the array.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | The count of the number of BLOBs is zero. |
| **E_POINTER** | A **NULL** pointer was provided as an argument. |
| **XACT_E_WRONGSTATE** | This method was called in the wrong state; either before [RegisterCompensator](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icrmlogcontrol-registercompensator) or when the transaction is completing (CRM Worker). |
| **XACT_E_ABORTED** | The transaction has aborted, most likely because of a transaction time-out. |

## Remarks

Unstructured records are simply a buffer of bytes. The method implements a gather capability by allowing sections of the specific CRM log record to be built up from an array of BLOBs, which is a structure containing a pointer to the data plus a count of the number of bytes. This reduces the copying of data, leading to only one copy directly from the CRM memory space into the buffer of the log manager.

Unstructured and structured log records cannot be mixed; either **WriteLogRecord** or [WriteLogRecordVariants](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-icrmlogcontrol-writelogrecordvariants) can be called, but not both by the same CRM Worker or CRM Compensator.

You should not include pointer types within datastructures contained in BLOBs in a log record. Object references are no longer valid during recovery phase because the CRM Compensator runs in a different process than that of the CRM Worker that wrote the log record. Including pointer types within BLOBs in a log record can cause an application to crash or corrupt itself during recovery.

## See also

[ICrmLogControl](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmlogcontrol)