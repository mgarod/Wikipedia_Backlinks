# Parsers
These miscellaneous tools were designed to extract data from the German Wikipedia. The relevant wikipedia pages were manually extracted from the source because each of the relevant pages are structured differently.

The CSV generator reads the text of these pages, and outputs only the relevant.

The make insert file reads the previously made CSV file and turns each line into a SQL insert statement.
