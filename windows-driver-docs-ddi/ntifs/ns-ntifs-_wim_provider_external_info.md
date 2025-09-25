# WIM_PROVIDER_EXTERNAL_INFO structure

## Description

The **WIM_PROVIDER_EXTERNAL_INFO** structure holds the identifier and status information for the Windows Image File (WIM) external backing provider.

## Members

### `Version`

The WIM provider version. Set to WIM_PROVIDER_CURRENT_VERSION.

### `Flags`

The status flags for the WIM provider. Set to 0 when active. Otherwise **Flags** is set to one of the following values.

| Value | Meaning |
| ----- | ------- |
| WIM_PROVIDER_EXTERNAL_FLAG_NOT_ACTIVE | The WIM provider is not active, which can occur when the WIM file is not found. In this case, the WIM file will not be recovered. |
| WIM_PROVIDER_EXTERNAL_FLAG_SUSPENDED | Indicates that the provider is dismounted. Recovery will be attempted. |

### `DataSourceId`

An identifier value for the WIM file data source.

### `ResourceHash`

An identifier for the object contained within the WIM. Conventionally a hash of the contents of a file, stored within the WIM.

## Remarks

The backing source for a file is set with a [**FSCTL_SET_EXTERNAL_BACKING**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-external-backing) control code request. The WIM file backing the file specified in the request is set in the **DataSourceId** member of **WIM_PROVIDER_EXTERNAL_INFO**.

The **Flags** and **ResourceHash** members are valid when the provider info is returned from a [**FSCTL_GET_EXTERNAL_BACKING**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-get-external-backing) request.

## See also

[**FSCTL_GET_EXTERNAL_BACKING**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-get-external-backing)

[**FSCTL_SET_EXTERNAL_BACKING**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-external-backing)