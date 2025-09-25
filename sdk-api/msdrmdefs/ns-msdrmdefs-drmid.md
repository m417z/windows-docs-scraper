# DRMID structure

## Description

>[!Note]
>[The AD RMS SDK leveraging functionality exposed by the client in Msdrm.dll is available for use in Windows Server 2008, Windows Vista, Windows Server 2008 R2, Windows 7, Windows Server 2012, and Windows 8. It may be altered or unavailable in subsequent versions. Instead, use [Active Directory Rights Management Services SDK 2.1](https://learn.microsoft.com/previous-versions/windows/desktop/msipc/microsoft-information-protection-and-control-client-portal), which leverages functionality exposed by the client in Msipc.dll.

The **DRMID** structure identifies an object. It is used by the [DRMBOUNDLICENSEPARAMS](https://learn.microsoft.com/windows/desktop/api/msdrmdefs/ns-msdrmdefs-drmboundlicenseparams) structure and by the [DRMCreateEnablingPrincipal](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateenablingprincipal) function.

## Members

### `uVersion`

Specifies the version of the structure. If you are programming in C, this should be set to **DRMIDVERSION** (0).

### `wszIDType`

A pointer to a null-terminated Unicode string that contains the ID type. If you are using this parameter to create a bound license, you must specify the same value that you set in the *wszIDType* parameter of the [DRMSetMetaData](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmsetmetadata) function. For more information, see [DRMBOUNDLICENSEPARAMS](https://learn.microsoft.com/windows/desktop/api/msdrmdefs/ns-msdrmdefs-drmboundlicenseparams). If you are using this parameter in the [DRMCreateEnablingPrincipal](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateenablingprincipal) function, the value can be **NULL**.

### `wszID`

A pointer to a null-terminated Unicode string that contains the object ID. If you are using this parameter to create a bound license, you must specify the same value that you set in the *wszID* parameter of the [DRMSetMetaData](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmsetmetadata) function. For more information, see [DRMBOUNDLICENSEPARAMS](https://learn.microsoft.com/windows/desktop/api/msdrmdefs/ns-msdrmdefs-drmboundlicenseparams). If you are using this parameter in the [DRMCreateEnablingPrincipal](https://learn.microsoft.com/previous-versions/windows/desktop/api/msdrm/nf-msdrm-drmcreateenablingprincipal) function, the value can be **NULL**.

### `_DRMID`

TBD

## Remarks

In a C++ application, this structure will have a default constructor that initializes the members to the following values.

```cpp
uVersion = DRMIDVERSION
wszIDType = NULL
wszID = NULL

```

An overloaded C++ constructor is also defined as follows.

```cpp
DRMID(PWSTR wszIDType, PWSTR wszID)
```

 This constructor will initialize the members to the following values.

```cpp
uVersion = DRMIDVERSION
wszIDType = wszTypein
wszID = wszIDin

```

## See also

[AD RMS Structures](https://learn.microsoft.com/previous-versions/windows/desktop/adrms_sdk/ad-rms-structures)

[DRMBOUNDLICENSEPARAMS](https://learn.microsoft.com/windows/desktop/api/msdrmdefs/ns-msdrmdefs-drmboundlicenseparams)