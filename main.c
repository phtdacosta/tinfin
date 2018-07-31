#include "tinfin.h"
#include <string.h>
#include <stdio.h>

char *greetings (request_t *args) {
    char *r;
    // Hardcoded sample of a HTML response (HTTP)
    char *r = HTTPResponse("200 OK", "text/html", "<html><h1>Welcome to Tinfin!</h1></html>", r);
    return r;
}

char *data (request_t *args) {
    // Hardcoded sample of a JSON response (HTTP)
    char *r;
    r = parseresponse("200 OK", "application/json", "{\"planet\":\"Mars\",\"site\":\"Olympus Mons\"}", r);
    return greetings;
}


int main (void) {
    // Hardcoded sample of a JSON response (HTTP)
    request_t *request = parserequest("GET /greetings HTTP/1.0\r\n{\"question\":\"Where am I?\"}");
    // Initialize an instance of a route table
    table_t *table = inittable();
    // Add two new custom routes into the table
    createroute("GET", "/", &greetings, table);
    createroute("GET", "/data", &data, table);
    // Based on the parsed request resource, the function associated with it (stored into the route table) is executed
    executeroute(request, table);
    // It does all the job freeing the routing table contents
    freetable(table);
}