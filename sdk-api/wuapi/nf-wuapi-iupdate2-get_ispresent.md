# IUpdate2::get_IsPresent

## Description

Gets a Boolean value that indicates whether an update is present on a computer.

This property is read-only.

## Parameters

## Remarks

An update is considered present if it is installed for one or more products. For example, if an update applies to both Microsoft Office Word and to Microsoft Office Excel, the **IsPresent** property returns **VARIANT_TRUE** if the update is installed for one or both of the products.

If an update applies to only one product, the **IsPresent** and [IsInstalled](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate-get_isinstalled) properties are equivalent. An update is considered installed if the update is installed for all the products to which it applies.

If **IsPresent** returns **VARIANT_TRUE** and [IsInstalled](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdate-get_isinstalled) returns **VARIANT_FALSE**, the update can be uninstalled for the product that installed it.

## See also

[IUpdate2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate2)