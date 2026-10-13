# Write your MySQL query statement below
select d.name as Department,e.name as Employee,e.salary as Salary
from employee e
INNER JOIN department d
on e.departmentid = d.id
where e.salary = (
    select MAX(salary)
    from employee e2
    where e2.departmentid = e.departmentid
)