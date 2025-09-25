# CrmLogRecordRead structure

## Description

Contains unstructured log records for the Compensating Resource Manager (CRM).

## Members

### `dwCrmFlags`

Information about when this record was written. For a list of values, see [CRMFLAGS](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-crmflags).

### `dwSequenceNumber`

The sequence number of the log record. Sequence numbers are not necessarily contiguous because not all internal log records or forgotten log records are delivered to the CRM Compensator.

### `blobUserData`

The user data.

## See also

[ICrmCompensator](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmcompensator)

[ICrmFormatLogRecords](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmformatlogrecords)