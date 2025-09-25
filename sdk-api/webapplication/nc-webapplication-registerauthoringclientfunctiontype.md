# RegisterAuthoringClientFunctionType callback function

## Description

Defines a pointer to an application-defined function in a dynamic-link library (DLL) that will be used as the authoring binary. When the app host starts in authoring mode, this function is called to initialize the authoring binary.

## Parameters

### `authoringModeObject` [in]

Type: **[IWebApplicationAuthoringMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/webapplication/nn-webapplication-iwebapplicationauthoringmode)***

An object that provides a path to the authoring binary.

### `host` [in]

Type: **[IWebApplicationHost](https://learn.microsoft.com/previous-versions/windows/desktop/api/webapplication/nn-webapplication-iwebapplicationhost)***

The WWAHost.

## Return value

Type: **HRESULT**

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[UnregisterAuthoringClientFunctionType](https://learn.microsoft.com/previous-versions/windows/desktop/api/webapplication/nc-webapplication-unregisterauthoringclientfunctiontype)