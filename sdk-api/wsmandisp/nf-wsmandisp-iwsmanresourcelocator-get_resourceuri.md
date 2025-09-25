# IWSManResourceLocator::get_ResourceURI

## Description

The [resource URI](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary) of the requested resource. This property can contain only the path, not a query string for specific instances.

This property is read/write.

## Parameters

## Remarks

[ResourceLocator](https://learn.microsoft.com/windows/desktop/WinRM/resourcelocator) is the corresponding scripting object for the [IWSManResourceLocator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanresourcelocator) interface.

The following is an example of a proper path for **ResourceURI**.

``` syntax
"http://schemas.microsoft.com/wbem/wsman/1/wmi/root/cimv2/Win32_Service"
```

The following path does not work because it contains a key for a specific instance. Use the [IWSManResourceLocator::AddSelector](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmanresourcelocator-addselector) method to specify a particular instance.

``` syntax
"http://schemas.microsoft.com/wbem/wsman/1/wmi/root/cimv2/Win32_Service?Name=winmgmt"
```

The corresponding scripting method is [ResourceLocator.ResourceURI](https://learn.microsoft.com/windows/desktop/WinRM/resourcelocator-resourceuri).

## See also

[IWSManResourceLocator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanresourcelocator)

[ResourceLocator.ResourceURI](https://learn.microsoft.com/windows/desktop/WinRM/resourcelocator-resourceuri)