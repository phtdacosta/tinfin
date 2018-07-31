# Welcome to Tinfin
Simple, lightweight and cross-platform support library for networking protocols (currently supporting only HTTP) in C99

## Main features
* Plenty of **specialized functions under the hood** for performant text processing
* **Simple and efficient routing table** engine compatible with any protocol
* **Easy to modify and add support** to other network protocols
* **Basic HTTP *request* parse** by default before transferred to the user-defined functions
* Practical to **parse and add custom headers to a HTTP *response***

## Quickstart
The repository itself offers a sample `main.c` file which also works as a test, containing the basic usage of all major functions available in the library.
> **It is recommended that newcomers read, modify and compile this file themselves**, because there is no better way to learn something than trying it!

## Download and test
```
> git clone https://github.com/phtdacosta/tinfin.git
> cd tinfin
```
The **Makefile** script included generates the binary file automatically.
```
> make build
> main
```

## Documentation

### `table_t *inittable (void);`
This function allocates enough memory for a `table_t` variable and returns the pointer address. Needed to use the route table.
### `void freetable (table_t *table);`
This function clears the memory previously used by the initialized route table and returns void.
### `int createroute (char *method, char *resource, char *(*function)(request_t *args), table_t *table);`
This function creates a new custom route that is added into the initialized route table for subsequent use. Needed to set any *resource endpoints*.
### `char *executeroute (request_t* request, table_t *table);`
This function tries to match the resource of the request received with any previously set routes, the resource is found in the route table, the function associated with it is automatically executed and the `char *` output, returned.
### `request_t *parserequest (char *raw);`
This function simply takes a raw `char *` request and returns the parsed `request_t` structure.
### `char *addheader (const char *field, const char *value, char *ptr);`
This function makes it practical to concatenate HTTP-like headers into a `char *` which was previously allocated with enough memory. It consumes the pointer given as a parameter and returns a new pointer to the current end position of the `char *`.
### `char *parseresponse (char *status_code, char *content_type, char *body, size_t buffer_size, char *res);`
This function parses the given parameters into a basic HTTP-like response and automatically allocates enough space for the `char *` address returned.

## License and usage
Tinfin is **open source** currently under the GPL 3.0 [license](#https://github.com/phtdacosta/tinfin/blob/master/LICENSE).
*Any specific use for the project will probably require code changes.*
  
### Contributions
Open an issue to discuss any found bugs or enhancement ideas.
### Vision
**Tinfin** is going to be maintained, fixing unexpected behaviors, enhancing HTTP compatibility, adding support for other networking protocols and improving existing functions towards performance, whenever possible.

## Known issues
Currently there are no known issues.