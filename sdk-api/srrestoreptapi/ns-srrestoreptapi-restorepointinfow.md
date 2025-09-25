# RESTOREPOINTINFOW structure

## Description

Contains information used by the
[SRSetRestorePoint](https://learn.microsoft.com/windows/desktop/api/srrestoreptapi/nf-srrestoreptapi-srsetrestorepointa) function.

## Members

### `dwEventType`

The type of event. This member can be one of the following values.

| Event type | Meaning |
| --- | --- |
| **BEGIN_NESTED_SYSTEM_CHANGE**<br><br>102 | A system change has begun. A subsequent nested call does not create a new restore point. <br><br>Subsequent calls must use END_NESTED_SYSTEM_CHANGE, not END_SYSTEM_CHANGE. |
| **BEGIN_SYSTEM_CHANGE**<br><br>100 | A system change has begun. |
| **END_NESTED_SYSTEM_CHANGE**<br><br>103 | A system change has ended. |
| **END_SYSTEM_CHANGE**<br><br>101 | A system change has ended. |

### `dwRestorePtType`

The type of restore point. This member can be one of the following values.

| Restore point type | Meaning |
| --- | --- |
| **APPLICATION_INSTALL**<br><br>0 | An application has been installed. |
| **APPLICATION_UNINSTALL**<br><br>1 | An application has been uninstalled. |
| **DEVICE_DRIVER_INSTALL**<br><br>10 | A device driver has been installed. |
| **MODIFY_SETTINGS**<br><br>12 | An application has had features added or removed. |
| **CANCELLED_OPERATION**<br><br>13 | An application needs to delete the restore point it created. For example, an application would use this flag when a user cancels an installation. |

### `llSequenceNumber`

The sequence number of the restore point. To end a system change, set this to the sequence number returned by the previous call to
[SRSetRestorePoint](https://learn.microsoft.com/windows/desktop/api/srrestoreptapi/nf-srrestoreptapi-srsetrestorepointa).

### `szDescription`

The description to be displayed so the user can easily identify a restore point. The maximum length of an ANSI string is MAX_DESC. The maximum length of a Unicode string is MAX_DESC_W. For more information, see
[Restore Point Description Text](https://learn.microsoft.com/windows/desktop/sr/restore-point-description-text).

## See also

[SRSetRestorePoint](https://learn.microsoft.com/windows/desktop/api/srrestoreptapi/nf-srrestoreptapi-srsetrestorepointa)

## Remarks

> [!NOTE]
> The srrestoreptapi.h header defines RESTOREPOINTINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).