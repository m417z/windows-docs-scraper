# IWebProxy::get_AutoDetect

## Description

Gets and sets a Boolean value that indicates whether [IWebProxy](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iwebproxy) automatically detects proxy settings.

This property is read/write.

## Parameters

## Remarks

The values of the [Address](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iwebproxy-get_address), [BypassList](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iwebproxy-get_bypasslist), and [BypassProxyOnLocal](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iwebproxy-get_bypassproxyonlocal) properties are ignored if the value of the **AutoDetect** property is set to **VARIANT_TRUE**.

## See also

[IWebProxy](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iwebproxy)