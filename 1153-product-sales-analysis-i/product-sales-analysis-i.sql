# Write your MySQL query statement below
select p.product_name,s.year,s.price
from product p
INNER JOIN sales s
on p.product_id = s.product_id
