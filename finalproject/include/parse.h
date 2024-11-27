#ifndef PARSE_H
#define PARSE_H

#define HEADER_MAGIC 0x4c4c4144

struct dbheader_t {
	unsigned int magic;
	unsigned int filesize;
	unsigned short version;
	unsigned short count;
};

struct employee_t {
	char name[256];
	char address[256];
	unsigned int hours;
};

// Currently in use
int create_db_header(int fd, struct dbheader_t **headerOut);

// Currently in use
int validate_db_header(int fd, struct dbheader_t **headerOut);

int read_employees(int fd, struct dbheader_t *, struct employee_t **employeesOut);

// Currently in use
// Consider changing it back to a void return type
void output_file(int fd, struct dbheader_t *);

void list_employees(struct dbheader_t *dbhdr, struct employee_t *employees);

int add_employee(struct dbheader_t *dbhdr, struct employee_t *employees, char *addstring);

#endif
