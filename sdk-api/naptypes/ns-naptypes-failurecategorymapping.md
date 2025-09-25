# FailureCategoryMapping structure

## Description

**Note** The Network Access Protection platform is not available starting with Windows 10

The **FailureCategoryMapping** structure contains optional compliance state information that is returned by the System Health Validator (SHV).

## Members

### `mappingCompliance`

An array of **BOOLs** that contain the compliance state of each [FailureCategory](https://learn.microsoft.com/windows/desktop/api/naptypes/ne-naptypes-failurecategory). **TRUE** indicates the category is compliant and **FALSE** indicates non-compliance.

**Note** The length of **mappingCompliance** is defined by [failureCategoryCount](https://learn.microsoft.com/windows/desktop/NAP/nap-type-constants).

## Remarks

If a failure occurs in the system (for example, a component or communication failures), the SHV may return
an [sohAttributeTypeFailureCategory](https://learn.microsoft.com/windows/desktop/NAP/sohattributetype-enum) type type-length-value (TLV) object in its [SoHResponse](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-soh) instead
of making a compliance decision. In turn, the NAP system maps the [FailureCategory](https://learn.microsoft.com/windows/desktop/api/naptypes/ne-naptypes-failurecategory) type returned by the TLV object to compliant or non-compliant within the **FailureCategoryMapping** structure as follows:

* mappingCompliance[0] = mapping for [failureCategoryOther](https://learn.microsoft.com/windows/desktop/api/naptypes/ne-naptypes-failurecategory)
* mappingCompliance[1] = mapping for [failureCategoryClientComponent](https://learn.microsoft.com/windows/desktop/api/naptypes/ne-naptypes-failurecategory)
* mappingCompliance[2] = mapping for [failureCategoryClientCommunication](https://learn.microsoft.com/windows/desktop/api/naptypes/ne-naptypes-failurecategory)
* mappingCompliance[3] = mapping for [failureCategoryServerComponent](https://learn.microsoft.com/windows/desktop/api/naptypes/ne-naptypes-failurecategory)
* mappingCompliance[4] = mapping for [failureCategoryServerCommunication](https://learn.microsoft.com/windows/desktop/api/naptypes/ne-naptypes-failurecategory)

By default, all categories map to non-compliant (FALSE).

## See also

[FailureCategory](https://learn.microsoft.com/windows/desktop/api/naptypes/ne-naptypes-failurecategory)