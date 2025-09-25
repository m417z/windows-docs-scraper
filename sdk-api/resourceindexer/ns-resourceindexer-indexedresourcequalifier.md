# IndexedResourceQualifier structure

## Description

Represents the context under which a resource is appropriate.

## Members

### `name`

The name of the qualifier, such as "language", "contrast", or "scale".

### `value`

The value of the qualifier. You should preserve the case of the qualifier value from the first instance of the qualifier discovered during indexing.

The following values are examples of the qualifier values:

* "100", "140", or "180" for scale.
* "fr-FR" for language.
* "high" for contrast.

## See also

[DestroyIndexedResults](https://learn.microsoft.com/windows/desktop/api/resourceindexer/nf-resourceindexer-destroyindexedresults)

[IndexFilePath](https://learn.microsoft.com/windows/desktop/api/resourceindexer/nf-resourceindexer-indexfilepath)