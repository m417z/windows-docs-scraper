# RtlNormalizeSecurityDescriptor function

## Description

This routine examines a security descriptor for ways to modify its layout, with the goal that any two equivalent security descriptors should be able to be single instanced in $SDS as often as possible, and a secondary goal that the stored security descriptor should be as small as possible.

## Parameters

### `SecurityDescriptor`

Pointer to a pointer to the SECURITY_DESCRIPTOR to normalize. The security descriptor must be in self-relative format. If **NewSecurityDescriptor** is not provided, this location may be updated with a newly allocated security descriptor from paged pool (freeing the original security descriptor) if modifications were made.

### `SecurityDescriptorLength`

Length in bytes of the security descriptor to normalize.

### `NewSecurityDescriptor`

If present and points to NULL, receives a pointer to a newly allocated security descriptor from paged pool if modifications were made, instead of updating **SecurityDescriptor**.

If present and points to non-NULL, a modified security descriptor is instead constructed directly in the buffer (assumed to be at least of length **SecurityDescriptorLength**) provided by the caller.

### `NewSecurityDescriptorLength`

Optionally receives the length in bytes of the modified security descriptor if this routine makes modifications.

### `CheckOnly`

A BOOLEAN value that if TRUE specifies that the routine should take no action when modifications would otherwise be made. In this case, a modified security descriptor is not created.

## Return value

Returns TRUE if modifications were made or would have been made and FALSE otherwise (including failure).

## Remarks

If this routine makes any modifications, it returns the modified security descriptor unless the caller specifies CheckOnly indicating that they only want to know if modifications would be made.

The transformations currently supported are:

- Arrange the sections in the order Sacl => Dacl => Owner => Group.

- Eliminate unnecessary padding (beyond simple alignment) between sections.

- Zero any alignment bytes between sections.

- Eliminate any Sacl that contains no ACEs.

- Eliminate duplicate ALLOW ACEs in the Sacl and Dacl.

## See also