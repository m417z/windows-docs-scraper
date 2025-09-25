## Description

**KsDeleteFilterFactory** deletes a given filter factory.

## Parameters

### `FilterFactory` [in]

A pointer to a [**KSFILTERFACTORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory) structure that represents the filter factory to be deleted.

## Remarks

This macro wraps and assumes the return value of [KsFreeObjectCreateItemsByContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfreeobjectcreateitemsbycontext), which is **NTSTATUS**.

## See also

[KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory)

[KsCreateFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatefilterfactory)

[KsFilterFactoryAddCreateItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterfactoryaddcreateitem)

[KsFilterFactorySetDeviceClassesState](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterfactorysetdeviceclassesstate)