# ExtRemoteTyped::HasField

## Description

The **HasField** method determines if the type of the data represented by this object contains the specified member.

## Parameters

### `Field` [in]

The name of the member. The name of the member is a dot-separated path and can contain sub-members (for example, **mymember.mysubmember**). Pointers on this dot-separated path will automatically be dereferenced. However, a dot operator (**.**) should still be used here instead of the usual C pointer dereference operator (**->**).

## Return value

**HasField** returns `true` if the typed data contains the member; `false` otherwise.