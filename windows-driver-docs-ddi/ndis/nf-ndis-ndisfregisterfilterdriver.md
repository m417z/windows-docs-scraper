# NdisFRegisterFilterDriver function

## Description

A filter driver calls the
**NdisFRegisterFilterDriver** function to register its
*FilterXxx* functions with NDIS.

## Parameters

### `DriverObject` [in]

A pointer to an opaque driver object that the filter driver received in its
[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine at the
*Argument1* parameter. (For more information, see
[DriverEntry of NDIS Filter
Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/initializing-a-filter-driver).)

### `FilterDriverContext` [in]

A handle to a driver-allocated context area where the driver maintains state and configuration
information.

### `FilterDriverCharacteristics`

A pointer to an
[NDIS_FILTER_DRIVER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_driver_characteristics) structure that the filter driver created and initialized with
its
*FilterXxx* function entry points.

### `NdisFilterDriverHandle` [out]

A pointer to a handle variable. If the call to
**NdisFRegisterFilterDriver** succeeds, NDIS fills this variable with a filter driver handle. The
filter driver saves this handle and later passes this handle to NDIS functions, such as
[NdisFDeregisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfderegisterfilterdriver),
that require a filter driver handle as an input parameter.

## Return value

**NdisFRegisterFilterDriver** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | [NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) returns NDIS_STATUS_SUCCESS if it registered the filter driver. |
| **NDIS_STATUS_BAD_VERSION** | The version that is specified in the **MajorNdisVersion** member of the structure at *FilterCharacteristics* is invalid. |
| **NDIS_STATUS_BAD_CHARACTERISTICS** | At least one of the members that are specified in [NDIS_FILTER_DRIVER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_driver_characteristics) is invalid. |
| **NDIS_STATUS_INVALID_PARAMETER** | At least one of the input parameters that the driver passed to [NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) is invalid. |
| **NDIS_STATUS_RESOURCES** | [NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) failed because of insufficient resources. |
| **NDIS_STATUS_FAILURE** | [NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver) returns NDIS_STATUS_FAILURE if none of the preceding values applies. |

## Remarks

A filter driver calls the
**NdisFRegisterFilterDriver** function from its
[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine. For more information about
**DriverEntry**, see
[DriverEntry of NDIS Filter
Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/initializing-a-filter-driver).

Drivers that call **NdisFRegisterFilterDriver** must be prepared for an immediate call to any of their *FilterXxx* functions. For more information see [Initializing a Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/network/initializing-a-filter-driver).

Every filter driver exports a set of
*FilterXxx* functions by setting up the
[NDIS_FILTER_DRIVER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_driver_characteristics) structure and calling
**NdisFRegisterFilterDriver**. NDIS copies this structure to the NDIS library's internal storage.

To allow filter drivers to register optional services, NDIS calls the
[FilterSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function within the
context of
**NdisFRegisterFilterDriver**.

After it has registered, a filter driver can later call the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function
to change the entry points for optional
*FilterXxx* functions.

Filter drivers call the
[NdisFDeregisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfderegisterfilterdriver) function to release resources that were previously allocated with
**NdisFRegisterFilterDriver**.

## See also

[DriverEntry of NDIS Filter
Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/initializing-a-filter-driver)

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[Initializing a Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/network/initializing-a-filter-driver)

[NDIS_FILTER_DRIVER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_filter_driver_characteristics)

[NdisFDeregisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfderegisterfilterdriver)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)