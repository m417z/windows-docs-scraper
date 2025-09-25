# LDAPVLVInfo structure

## Description

The **LDAPVLVInfo** structure is used to set up the search parameters for a virtual list view (VLV) request control ([LDAP_CONTROL_VLVREQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvrequest)).

The **LDAPVLVInfo** structure may also be used by applications to manage the state data associated with a series of VLV client/server interactions.

## Members

### `ldvlv_version`

Identifies the version of the **LDAPVLVInfo** structure. This should always be set to the value LDAP_VLVINFO_VERSION (1).

### `ldvlv_before_count`

Identifies the number of entries before the target entry that the client wants the server to send back in the list results. This field corresponds to the **beforeCount** element of the BER-encoded [LDAP_CONTROL_VLVREQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvrequest) control.

### `ldvlv_after_count`

Indicates the number of entries after the target entry the client instructs the server to send back in the list results. This field corresponds to the **afterCount** element of the BER-encoded [LDAP_CONTROL_VLVREQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvrequest) control.

### `ldvlv_offset`

Indicates a ratio between the offset value and the content count. For example, consider if a user drags the scroll bar to view entries in the middle of the list. If the client estimates that the entire list contains 100 entries, then to view the middle list it will calculate the offset to be 50, so the client sends this offset value, with 100 as the content count, sent in the **ldvlv_count** member, to the server. When the server receives this data, it may actually have calculated the content count to be 500, so it calculates the offset to find the target that the client requested, using the following formula:

Si = Sc * (Ci / Cc)

where

Si is the actual list offset used by the server

Sc is the server estimate for content count

Ci is the client-submitted offset

Cc is the client-submitted content count

If the client uses an offset value of one (1), it indicates that the target is the first entry in the list. If the client uses an offset value that equals **ldvlv_count**, then the item is the last entry in the list. The offset will equal zero (0) when **ldvlv_count** equals zero, which would be the last entry in the list.

Offsets are used only if the search is not based on an attribute value, so **ldvlv_attrvalue** must be **NULL**. This field corresponds to the offset element within the BER-encoded [LDAP_CONTROL_VLVREQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvrequest) control.

### `ldvlv_count`

Indicates the content count of the list. An estimation of the content count is sent by the client to the server when sending a search request, in order to enable the server to calculate an offset value. The server returns its own calculation of the content count to the client in its response. If the client does not have an estimate for content count, it sends zero (0), which indicates that the server should use its own estimate for content count. This member is used with **ldvlv_offset**. Because content count is required only if the search is not based on an attribute value, the **ldvlv_attrvalue** member must be **NULL**. This field corresponds to the **contentCount** element within the BER-encoded [LDAP_CONTROL_VLVREQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvrequest) control and the **contentCount** element within the BER-encoded [LDAP_CONTROL_VLVRESPONSE](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvresponse) control.

### `ldvlv_attrvalue`

Provides an attribute value as a target entry for the search. The server compares this member to values that have the same attribute type, as specified in the **sk_attrtype** member of the [LDAPSortKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapsortkeya) structure. If an offset is used, then this member must be **NULL**. This member corresponds to the **assertionValue** element of the BER-encoded [LDAP_CONTROL_VLVREQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvrequest) control.

### `ldvlv_context`

Provides the context ID that is assigned by the server to identify this search operation. This is an opaque "cookie" used by the server to keep internal track of the current VLV operation. On the first call to the search operation using the VLV control, this parameter should be set to **NULL**. The server may return a value in the [LDAP_CONTROL_VLVRESPONSE](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvresponse) message. This "cookie" value should be returned to the server on the next call to a search function that is performed against a particular VLV list.

### `ldvlv_extradata`

This field is reserved for application-specific use and is not used by the [ldap_create_vlv_control](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_create_vlv_controla) function; it has no effect on the control that is created.

## Remarks

There are two methods for calculating the target of a VLV search: using an attribute value or using an offset. Different elements of this structure will be used depending on which type of search you choose. Both methods require that values be entered for the **ldvlv_before_count** and **ldvlv_after_count** members. Specify a list content count in **ldvlv_count**, or if you do not know this value, then use zero (0), so that the server will calculate it.

* Searching with Attribute Values

  To perform a value-based search, for example, if you wanted to search for Jeff Smith, and you know the attribute type for that value, then set the attribute type in the **sk_attrtype** member of the [LDAPSortKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapsortkeya) structure and the attribute value in **ldvlv_attrvalue**. The **ldvlv_offset** member is ignored for this type of search, so it is not necessary to set it.

  For example, to perform a search using the letter J. To retrieve 20 results, set **ldvlv_before_count** to 9, **ldvlv_after_count** to 10 and **ldvlv_attrvalue** to J. The server finds the first entry in the list that is not less than J, such as Jeff Smith, and returns the nine preceding entries, the target entry, and the proceeding 10 entries. The server would return a **ldvlv_count** of 30000 and a **ldvlv_offset** of 4053 in the [LDAP_CONTROL_VLVRESPONSE](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvresponse) control; that is assuming that Jeff Smith is entry number 4053 on the list. The server may return few entries than requested before and/or after the target entry if there are insufficient entries in the list to satisfy the request. For example, if there were only two entries total before the first 'J' entry, the server could not return nine preceding entries.
* Searching with Offsets

  To use offsets for your search, set an offset in **ldvlv_offset**, and set **ldvlv_attrvalue** to **NULL**. Also set the attribute type in the **sk_attrtype** member of the [LDAPSortKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapsortkeya), but this time, the target will be an offset within the list of entries for that attribute type, rather than a specific attribute value.

  For example, to target the search 68 percent of the search results list. If the **ldvlv_count** is 30000, the 68 percent of 30000 is 20400. To retrieve 20 results, set **ldvlv_before_count** to 9, **ldvlv_after_count** to 10, **ldvlv_count** to 30000, **ldvlv_offset** to 20400 and send the request to the server. The server returns the preceding 20 entries in the list, plus the **ldvlv_count** of 30000 and a **ldvlv_offset** of 20400. Be aware that it is possible for the number of entries on the list to change between the client estimation of the number of entries and the server processing the search, which in turn effects the offsets. In this case the target entry returned may not be exactly the target entry the client was expecting. Applications must be prepared to handle this uncertainty.

Be aware that a sort control must accompany a VLV search request to specify the ordered list of entries against which the VLV search is performed. Servers can reject VLV searches performed against lists for which they do not have indexes.

## See also

[LDAPControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-ldapcontrola)

[LDAP_CONTROL_VLVREQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvrequest)

[LDAP_CONTROL_VLVRESPONSE](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/ldap-control-vlvresponse)

[Searching with the LDAP VLV Control](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/searching-with-the-ldap-vlv-control)

[ldap_create_sort_control](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_create_sort_control)

[ldap_create_vlv_control](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_create_vlv_controla)

[ldap_parse_vlv_control](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_parse_vlv_controla)

[ldap_search_ext](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_ext)

[ldap_search_ext_s](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_search_ext_s)