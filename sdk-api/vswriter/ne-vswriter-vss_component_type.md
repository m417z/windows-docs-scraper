# VSS_COMPONENT_TYPE enumeration

## Description

The **VSS_COMPONENT_TYPE** enumeration is used by both
the requester and the writer to specify the type of component being used with a shadow copy backup
operation.

## Constants

### `VSS_CT_UNDEFINED:0`

Undefined component type.

This value indicates an application error.

### `VSS_CT_DATABASE`

Database component.

### `VSS_CT_FILEGROUP`

File group component. This is any component other than a database.

## Remarks

A writer sets a component's type when it adds the component to its Writer Metadata Document using
[IVssCreateWriterMetadata::AddComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addcomponent).

Writers and requesters can find the type information of components selected for inclusion in a Backup
Components Document through calls to
[IVssComponent::GetComponentType](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getcomponenttype) to return
a component type directly.

A requester can obtain the type of any component in a given writer's Writer Metadata Document by doing the
following:

1. Using
   [IVssExamineWriterMetadata::GetComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getcomponent)
   to obtain a [IVssWMComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivsswmcomponent) interface
2. Using
   [IVssWMComponent::GetComponentInfo](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivsswmcomponent-getcomponentinfo) to
   return a [VSS_COMPONENTINFO](https://learn.microsoft.com/windows/desktop/api/vsbackup/ns-vsbackup-vss_componentinfo) structure
3. Examining the **Type** member of the
   [VSS_COMPONENTINFO](https://learn.microsoft.com/windows/desktop/api/vsbackup/ns-vsbackup-vss_componentinfo) object

## See also

[IVssComponent::GetComponentType](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getcomponenttype)

[VSS_COMPONENTINFO](https://learn.microsoft.com/windows/desktop/api/vsbackup/ns-vsbackup-vss_componentinfo)

[VSS_SOURCE_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_source_type)