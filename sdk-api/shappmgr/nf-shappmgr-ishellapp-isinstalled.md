# IShellApp::IsInstalled

## Description

Gets a value indicating whether a specified application is currently installed.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The application is installed. |
| **S_FALSE** | The application is not installed. |

## Remarks

Application publishers should determine if the application is currently installed and return S_OK if so, or S_FALSE if not.

## See also

[IAppPublisher](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-iapppublisher)

[IPublishedApp](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ipublishedapp)

[IShellApp](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ishellapp)