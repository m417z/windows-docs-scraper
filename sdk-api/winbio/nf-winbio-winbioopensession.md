# WinBioOpenSession function

## Description

Connects to a biometric service provider and one or more biometric units.

## Parameters

### `Factor` [in]

A bitmask of [WINBIO_BIOMETRIC_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/winbio_ioctl/ns-winbio_ioctl-_winbio_sensor_attributes) flags that specifies the biometric unit types to be enumerated. Only **WINBIO_TYPE_FINGERPRINT** is currently supported.

### `PoolType` [in]

A **ULONG** value that specifies the type of the biometric units that will be used in the session. This can be one of the following values:

| Value | Meaning |
| --- | --- |
| **WINBIO_POOL_SYSTEM** | The session connects to a shared collection of biometric units managed by the service provider. |
| **WINBIO_POOL_PRIVATE** | The session connects to a collection of biometric units that are managed by the caller. |

### `Flags` [in]

A **ULONG** value that specifies biometric unit configuration and access characteristics for the new session. Configuration flags specify the general configuration of units in the session. Access flags specify how the application will use the biometric units. You must specify one configuration flag but you can combine that flag with any access flag.

| Value | Meaning |
| --- | --- |
| **WINBIO_FLAG_DEFAULT** | Group: configuration<br><br>The biometric units operate in the manner specified during installation. You must use this value when the *PoolType* parameter is WINBIO_POOL_SYSTEM. |
| **WINBIO_FLAG_BASIC** | Group: configuration<br><br>The biometric units operate only as basic capture devices. All processing, matching, and storage operations is performed by software plug-ins. |
| **WINBIO_FLAG_ADVANCED** | Group: configuration<br><br>The biometric units use internal processing and storage capabilities. |
| **WINBIO_FLAG_RAW** | Group: access<br><br>The client application captures raw biometric data using [WinBioCaptureSample](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocapturesample). |
| **WINBIO_FLAG_MAINTENANCE** | Group: access<br><br>The client performs vendor-defined control operations on a biometric unit by calling [WinBioControlUnitPrivileged](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiocontrolunitprivileged). |

### `UnitArray` [in]

Pointer to an array of biometric unit identifiers to be included in the session. You can call [WinBioEnumBiometricUnits](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioenumbiometricunits) to enumerate the biometric units. Set this value to **NULL** if the *PoolType* parameter is **WINBIO_POOL_SYSTEM**.

### `UnitCount` [in]

A value that specifies the number of elements in the array pointed to by the *UnitArray* parameter. Set this value to zero if the *PoolType* parameter is **WINBIO_POOL_SYSTEM**.

### `DatabaseId` [in]

A value that specifies the database(s) to be used by the session. If the *PoolType* parameter is **WINBIO_POOL_PRIVATE**, you must specify the GUID of an installed database. If the *PoolType* parameter is not **WINBIO_POOL_PRIVATE**, you can specify one of the following common values.

| Value | Meaning |
| --- | --- |
| **WINBIO_DB_DEFAULT** | Each biometric unit in the sensor pool uses the default database specified in the default biometric unit configuration. You must specify this value if the *PoolType* parameter is **WINBIO_POOL_SYSTEM**. You cannot use this value if the *PoolType* parameter is **WINBIO_POOL_PRIVATE** |
| **WINBIO_DB_BOOTSTRAP** | You can specify this value to be used for scenarios prior to starting Windows. Typically, the database is part of the sensor chip or is part of the BIOS and can only be used for template enrollment and deletion. |
| **WINBIO_DB_ONCHIP** | The database is on the sensor chip and is available for enrollment and matching. |

### `SessionHandle` [out]

Pointer to the new session handle. If the function does not succeed, the handle is set to zero.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments have incorrect values or are incompatible with other arguments. |
| **E_POINTER** | The session handle pointer in the *SessionHandle* parameter cannot be **NULL**. |
| **E_ACCESSDENIED** | The *Flags* parameter contains the **WINBIO_FLAG_RAW** or the **WINBIO_FLAG_MAINTENANCE** flag and the caller has not been granted either access permission. |
| **WINBIO_E_INVALID_UNIT** | One or more of the biometric unit numbers specified in the *UnitArray* parameter is not valid. |
| **WINBIO_E_NOT_ACTIVE_CONSOLE** | The client application is running on a remote desktop client and is attempting to open a system pool session. |
| **WINBIO_E_SENSOR_UNAVAILABLE** | The *PoolType* parameter is set to WINBIO_POOL_PRIVATE and one or more of the requested sensors in that pool is not available. |
| **WINBIO_E_DISABLED** | Current administrative policy prohibits use of the Windows Biometric Framework API. |

## See also

[WinBioCloseSession](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbioclosesession)