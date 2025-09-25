# IGPMAsyncProgress::Status

## Description

The server calls this method to notify the client about the status of a Group Policy Management Console (GPMC) operation.

## Parameters

### `lProgressNumerator` [in]

Numerator of a fraction that represents the percent of the GPMC operation that is complete.

### `lProgressDenominator` [in]

Denominator of a fraction that represents the percent of the GPMC operation that is complete. The value of this parameter is proportional to the number of extensions in the Group Policy object (GPO), whether the GPO is a "live" GPO or a backed-up GPO. This value can be used to display the progress bar to the user.

In the GPMC user interface, the progress bar is divided into *lProgressDenominator* intervals. When *lProgressNumerator*==*lProgressDenominator* the operation is complete.

### `hrStatus` [in]

Status of the operation. If no error occurred, the value of the parameter is **S_OK**.

### `pResult` [in]

Result of the operation.
This parameter is an interface pointer to the object that resulted from the GPMC operation. For example, it may be a pointer to a [GPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo) object or to a [GPMBackup](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmbackup) object. This object is only returned when the operation is complete.

### `ppIGPMStatusMsgCollection` [in]

A pointer to the [IGPMStatusMsgCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmstatusmsgcollection) interface that contains detailed status information about the operation. In cases where there are no errors, or if there are no detailed messages, Status passes in a null collection.

## Return value

This method has no return values.

## Remarks

This method must be implemented by the client.

## See also

[IGPMAsyncCancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasynccancel)

[IGPMAsyncProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmasyncprogress)