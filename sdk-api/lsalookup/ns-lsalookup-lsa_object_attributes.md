# LSA_OBJECT_ATTRIBUTES structure

## Description

The **LSA_OBJECT_ATTRIBUTES** structure is used with the
[LsaOpenPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaopenpolicy) function to specify the attributes of the connection to the [Policy](https://learn.microsoft.com/windows/desktop/SecMgmt/policy-object) object.

When you call [LsaOpenPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaopenpolicy), initialize the members of this structure to **NULL** or zero because the function does not use the information.

## Members

### `Length`

Specifies the size, in bytes, of the **LSA_OBJECT_ATTRIBUTES** structure.

### `RootDirectory`

Should be **NULL**.

### `ObjectName`

Should be **NULL**.

### `Attributes`

Should be zero.

### `SecurityDescriptor`

Should be **NULL**.

### `SecurityQualityOfService`

Should be **NULL**.

## Remarks

The **LSA_OBJECT_ATTRIBUTES** structure is defined in the LsaLookup.h header file.

**Windows Server 2008 with SP2 and earlier, Windows Vista with SP2 and earlier, Windows Server 2003, Windows XP/2000:** The **LSA_OBJECT_ATTRIBUTES** structure is defined in the NTSecAPI.h header file.

## See also

[LsaOpenPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaopenpolicy)

[SECURITY_QUALITY_OF_SERVICE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_quality_of_service)