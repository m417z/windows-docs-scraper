# IWebProxy::put_Address

## Description

Gets and sets the address and the decimal port number of the proxy server.

This property is read/write.

## Parameters

## Remarks

The value of the **Address** property is ignored if the value of the [AutoDetect](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iwebproxy-get_autodetect) property is set to **VARIANT_TRUE**.
When **Address** is a null reference (for example, if you specified Nothing in Visual Basic), all the requests bypass the proxy. The requests connect directly to the destination host.

## See also

[IWebProxy](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iwebproxy)