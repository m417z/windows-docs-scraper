# ExtRemoteTyped::Field

## Description

The **Field** method returns the typed data for a member in the typed data that is represented by this object.

## Parameters

### `Field` [in]

The name of the member whose typed data is requested. Sub-members can be specified using a dot-separated path (for example, **mymember.mysubmember**). Pointers on this dot-separated path will automatically be dereferenced. However, a dot operator (**.**) should still be used here instead of the usual C pointer dereference operator (**->**).

## Return value

**Field** returns a new **ExtRemoteTyped** object that represents the typed data for the specified member.