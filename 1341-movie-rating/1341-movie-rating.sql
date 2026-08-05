# Write your MySQL query statement below
select name as results from (select u.name as name,count(m.user_id) as movie_count from Users u join MovieRating m on u.user_id = m.user_id group by u.user_id order by movie_count desc,name limit 1) t
union all
select title from (select avg(rating) as rating_avg,m.title from Movies m join MovieRating r on m.movie_id = r.movie_id where year(r.created_at)=2020 and month(r.created_at)=02 group by m.title order by rating_avg desc,title limit 1) as p;