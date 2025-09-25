# CLUSPROP_RESOURCE_CLASS_INFO structure

## Description

Describes information relating to a resource class. It is used as an entry in a
[value list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/value-lists) and consists of:

* A [CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure indicating the format
  and type of the resource class information.
* A [CLUS_RESOURCE_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_resource_class_info) structure
  describing the resource class and subclass of the resource.

## Members

### `CLUSPROP_VALUE`

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure with a **cbLength** field indicating
the count of bytes in the **CLUS_RESOURCE_CLASS_INFO** member. Padding
bytes are not included in the count.

### `CLUS_RESOURCE_CLASS_INFO`

[CLUS_RESOURCE_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_resource_class_info) structure.

## Remarks

A resource class identifies resources of similar capability. A
[resource DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls) that defines its own resource class should
provide a unique identifier for the class that is set to a value greater than
**CLUS_RESCLASS_USER**. **CLUS_RESCLASS_USER** specifies the beginning
for user-defined resource class identifiers.

## See also

[CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax)

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value)

[CLUS_RESOURCE_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_resource_class_info)

[Data structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)