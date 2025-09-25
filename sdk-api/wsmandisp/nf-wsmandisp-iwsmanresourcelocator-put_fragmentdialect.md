# IWSManResourceLocator::put_FragmentDialect

## Description

Gets or sets the language dialect for a [resource](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary) [fragment](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary) *dialect* when [IWSManResourceLocator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanresourcelocator) is used in [IWSManSession](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmansession) object methods such as [Get](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmansession-get), [Put](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmansession-put), or [Enumerate](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmansession-enumerate). A fragment represents one property or part of a resource. You can provide an [IWSManResourceLocator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanresourcelocator) object instead of specifying a [resource URI](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary) in [IWSManSession](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmansession) object operations.

This property is read/write.

## Parameters

## Remarks

The dialect string defaults to the XPath 1.0 specification. For more information, see [http://www.w3.org/TR/xpath](https://www.w3.org/TR/xpath).

## See also

[IWSManResourceLocator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanresourcelocator)

[ResourceLocator.FragmentDialect](https://learn.microsoft.com/windows/desktop/WinRM/resourcelocator-fragmentdialect)