# SERVICE_TYPE_INFO_ABSW structure

## Description

The
**SERVICE_TYPE_INFO_ABS** structure contains information about a network service type. Use **SERVICE_TYPE_INFO_ABS** to add a network service type to a namespace.

## Members

### `lpTypeName`

Pointer to a zero-terminated string that is the name of the network service type. This name is the same in all namespaces, and is used by the
[GetTypeByName](https://learn.microsoft.com/windows/desktop/api/nspapi/nf-nspapi-gettypebynamea) and
**GetNameByType** functions.

### `dwValueCount`

Number of
[SERVICE_TYPE_VALUE_ABS](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_type_value_absa) structures in the **Values** member array that follows **dwValueCount**.

### `Values`

Array of
[SERVICE_TYPE_VALUE_ABS](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_type_value_absa) structures.

Each of these structures contains information about a service type value that the operating system or network service may need when an instance of this network service type is registered with a namespace.

The information in these structures may be specific to a namespace. For example, if a network service uses the SAP namespace, but does not have a **GUID** that contains the SAP identifier (SAPID), it defines the SAPID in a
[SERVICE_TYPE_VALUE_ABS](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_type_value_absa) structure.

## Remarks

When you use the
[SetService](https://learn.microsoft.com/windows/desktop/api/nspapi/nf-nspapi-setservicea) function to add a network service type to a namespace, the
**SERVICE_TYPE_INFO_ABS** structure is passed as the **ServiceSpecificInfo** BLOB member of a
[SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_infoa) structure. Although the **ServiceSpecificInfo** member generally should not contain pointers, an exception is made in the case of the
**SERVICE_TYPE_INFO_ABS** and
[SERVICE_TYPE_VALUE_ABS](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_type_value_absa) structures.

> [!NOTE]
> The nspapi.h header defines SERVICE_TYPE_INFO_ABS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_infoa)

[SERVICE_TYPE_VALUE_ABS](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_type_value_absa)

[SetService](https://learn.microsoft.com/windows/desktop/api/nspapi/nf-nspapi-setservicea)