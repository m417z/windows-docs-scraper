# UnregisterAuthoringClientFunctionType callback function

## Description

Unregisters the application-defined function that was registered with the [RegisterAuthoringClientFunctionType](https://learn.microsoft.com/previous-versions/windows/desktop/api/webapplication/nc-webapplication-registerauthoringclientfunctiontype) function. This function is called when the app host terminates.

## Parameters

### `host` [in]

Type: **[IWebApplicationHost](https://learn.microsoft.com/previous-versions/windows/desktop/api/webapplication/nn-webapplication-iwebapplicationhost)***

An object that provides a path to the authoring binary.

## Return value

Type: **HRESULT**

The WWAHost.

## See also

[RegisterAuthoringClientFunctionType](https://learn.microsoft.com/previous-versions/windows/desktop/api/webapplication/nc-webapplication-registerauthoringclientfunctiontype)